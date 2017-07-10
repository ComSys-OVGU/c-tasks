#ifndef TREE_H
#define TREE_H
#include <stdint.h>
#include <unistd.h>

/// @brief A student account as binary tree node
struct student {
	/// @brief Name of the student terminated by zero byte
	char name[32];
	/// @brief Enrollment number of the student
	uint32_t student_number;
	/// @brief Pointer to left child node or `NULL`. Left child has smaller `student_number`
	struct student *left;
	/// @brief Pointer to right child node or `NULL`. Right child has greater `student_number`
	struct student *right;
};

/// @brief The student database as binary tree
struct tree {
	/// @brief Pointer to the root of the tree, or `NULL` if empty
	struct student *root;
	/// @brief Number of students in DB
	size_t n_students;
};

/**
 * @brief Malloc and initialize a student tree node
 * @param number The enrollment number of the new student
 * @param name The name of the new student
 * @retval NULL If an argument was invalid (`errno` was set to `EINVAL`) or
 *              memory allocation failed (`errno` was set to `ENOMEM`)
 * @return Pointer to the new student node
 * @post If `NULL` is returned, no memory is leaked
 * @post The newly created student node was initialized with no child node and
 *       the given enrollment number and name
 */
struct student * create_student(uint32_t number, const char *name);

/**
 * @brief Initializes the given tree as an empty student database
 * @param tree Student DB to initialize
 * @post The given tree root pointer was set to `NULL` and the student count
 *       was set to zero.
 * @pre Parameter `tree` is not `NULL`, otherwise segmentation fault.
 */
void init_tree(struct tree *tree);

/**
 * @brief Inserts the given student in the given tree
 * @param tree Student database to insert the given student into
 * @param student Student to insert
 * @retval 0 Success
 * @retval -1 Failure: One of the given parameters was `NULL`. `errno` will
 *            be set to `EINVAL` in this case
 * @post The given student was added to the given tree without balancing
 *       (as leaf node) at the position determined by the enrollment number
 */
int insert_student(struct tree *tree, struct student *student);

/**
 * @brief Searches for the student identified by the given enrollment number
 * @param tree The student database to search in
 * @param number The enrollment number of the student to search
 * @retval NULL If no such student was found. `errno` will be set to `ENOKEY`
 * @retval NULL If the given DB was `NULL`. `errno` will be set to `EINVAL`
 * @return Pointer to the student record identified by the given enrollment
 *         number
 */
struct student * search_student(struct tree *tree, uint32_t number);

/**
 * @brief Run the given callback function for each student with an enrollment
 *        number within the range `[from; till]`
 * @param tree DB containing the student records to iterate over
 * @param from Iterate over enrollment numbers greater or equal to `from`
 * @param till Iterate over enrollment numbers less or equal to `till`
 * @param callback Function to call for each selected student recored
 * @param userdata Pointer passed as second argument to `callback`. `NULL` is
 *                 considered as valid.
 * @retval -1 If an invalid argument was passed. `errno` will be set to `EINVAL`
 * @return The number of students iterated over
 * @post The function `callback` was called for each identified student
 *       record exactly once in ascending order of enrollment number
 */
ssize_t foreach_student(struct tree *tree, uint32_t from, uint32_t till,
                        void callback(struct student *, void *userdata), 
                        void *userdata);
/**
 * @brief Remove each student record from the given tree and free its memory
 * @param tree Student DB to clear
 * @pre `tree` is different from `NULL`, othwise segmentation fault
 */
void delete_students(struct tree *tree);

#endif

