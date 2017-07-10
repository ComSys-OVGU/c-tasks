#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include <unit_test.h>

struct foreach_data{
	size_t *indices;
	size_t pos;
	size_t len;
};

static const char *names[] = {
	"The Atom",
	"Spider-Man",
	"Green Lantern",
	"Iran Man",
	"The Hulk",
	"Wonder Woman",
	"Hellboy",
	"Captain America",
	"Black Widow",
	"Nick Fury",
	"Laurel Kent",
	"Jenny Quantum",
	"Punisher",
	"Aquaman",
	"Invisible Woman",
	"Nightcrawler",
	"Wolverine",
	"Blade",
	"Superman",
	"Ghost Rider",
	"Daredevil",
	"Huntress",
	"Jinx",
	"Phoenix",
	"Black Canary",
	"Quicksilver",
	"Hawkeye",
	"Catwoman",
	"The Flash",
	"Deadpool",
	"Dr. Strange",
	"Antman",
	"Batman",
	"Green Arrow",
	NULL
};

static const uint32_t numbers[] = {
	3698326487,
	3610732648,
	894613067,
	2407740708,
	549898001,
	3628136369,
	1579296677,
	3205640989,
	629376530,
	2485564609,
	945628440,
	4193623367,
	1710841929,
	2053643688,
	543801351,
	3172224279,
	652929523,
	3987404120,
	2715386757,
	2920636463,
	145751062,
	4207864846,
	1646214802,
	1545962244,
	1453062910,
	1355478031,
	3631750912,
	197608081,
	1073999140,
	85074199,
	1791318381,
	347692687,
	1812285273,
	269946600,
	0
};

static void
validate_tree(struct student *node)
{
	if (node->left != NULL){
		TEST(node->left->student_number < node->student_number);
		validate_tree(node->left);
	}
	
	if (node->right != NULL){
		TEST(node->right->student_number > node->student_number);
		validate_tree(node->right);
	}
}

static void
test_create_and_insert(struct tree *tree)
{
	struct student *s;
	const char *name;
	uint32_t number;
	
	// Testing for argument checking
	errno = 0;
	s = create_student(42, NULL);
	TEST(s == NULL);
	TEST(errno == EINVAL);
	
	errno = 0;
	s = create_student(42, "Waaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaay too long name");
	TEST(s == NULL);
	TEST(errno == EINVAL);
	
	errno = 0;
	s = create_student(42, "A name exactly one char too long");
	TEST(s == NULL);
	TEST(errno == EINVAL);
	
	errno = 0;
	s = create_student(42, "A name exactly as long as valid");
	TEST(s != NULL);
	if (s != NULL)
		free(s);
	
	for (size_t i = 0; names[i] != NULL; i++){
		name = names[i];
		number = numbers[i];
		s = create_student(number, name);
		TEST(s != NULL);
		if (s == NULL)
			critical_fail();
		
		TEST(strcmp(name, s->name) == 0);
		TEST(number == s->student_number);
		TEST(s->left == NULL);
		TEST(s->right == NULL);
		TEST(insert_student(tree, s) == 0);
		TEST(tree->n_students == i + 1);
		validate_tree(tree->root);
	}
}

static void
test_search(struct tree *tree)
{
	struct student *s;
	const char *name;
	uint32_t number;
	
	// Testing for argument checking
	errno = 0;
	s = search_student(NULL, 5);
	TEST(s == NULL);
	TEST(errno == EINVAL);
	
	// Testing search for non-existing students
	for (uint32_t i = 0; i < 1000; i++){
		errno = 0;
		s = search_student(tree, i);
		TEST(s == NULL);
		TEST(errno == ENOKEY);
	}
	
	// Testing search for existing students
	for (size_t i = 0; names[i] != NULL; i++){
		name = names[i];
		number = numbers[i];
		s = search_student(tree, number);
		TEST(s != NULL);
		if (s != NULL){
			TEST(number == s->student_number);
			TEST(strcmp(name, s->name) == 0);
		} else {
			puts("WARNING: Skipped two tests because of previous error");
		}
	}
}

static void
foreach_callback(struct student *s, void *_data)
{
	struct foreach_data *data = _data;
	size_t exp;
	
	TEST(s != NULL);
	TEST(data != NULL);
	if ((s == NULL) || (data == NULL))
		critical_fail();
	
	TEST(data->pos < data->len);
	if (data->pos >= data->len)
		critical_fail();
	
	exp = data->indices[data->pos];
	
	TEST(numbers[exp] == s->student_number);
	if (numbers[exp] != s->student_number){
		printf("NOTE: Got %u, expected %u\n",
		       s->student_number, numbers[exp]);
	}
	TEST(strcmp(names[exp], s->name) == 0);
	if (numbers[exp] != s->student_number){
		printf("NOTE: Got %s, expected %s\n",
		       s->name, names[exp]);
	}
	data->pos++;
}

static void
test_foreach_student(struct tree *tree)
{
	// Indices of student names / numbers in range [100000000;999999999]
	size_t indices[] = {20, 27, 33, 31, 14, 4, 8, 16, 2, 10};
	size_t selection_size = sizeof(indices)/sizeof(indices[0]);
	struct foreach_data data = {
		.indices = indices,
		.pos = 0,
		.len = selection_size
	};
	ssize_t retval;
	
	// Test for argument checking
	errno = 0;
	TEST(foreach_student(NULL, 0, 1, foreach_callback, NULL) == -1);
	TEST(errno == EINVAL);
	
	errno = 0;
	TEST(foreach_student(tree, 0, 1, NULL, NULL) == -1);
	TEST(errno == EINVAL);
	
	errno = 0;
	TEST(foreach_student(tree, 1, 0, foreach_callback, NULL) == -1);
	TEST(errno == EINVAL);
	
	// Test empty selection:
	TEST(foreach_student(tree, 0, 1, foreach_callback, NULL) == 0);
	
	// Test valid selection
	
	retval = foreach_student(tree, 100000000, 999999999,
	                         foreach_callback, &data);
	TEST((ssize_t)selection_size == retval);
	if ((ssize_t)selection_size != retval){
		printf("NOTE: Got %zd, expected %zd\n", retval, selection_size);
	}
	TEST(data.pos == selection_size);
}

int
main(void)
{
	struct tree tree = {.root = (void *)42, .n_students = 200};
	
	test_init();
	
	init_tree(&tree);
	TEST(tree.root == NULL);
	TEST(tree.n_students == 0);
	
	test_create_and_insert(&tree);
	test_search(&tree);
	test_foreach_student(&tree);
	
	delete_students(&tree);
	TEST(tree.n_students == 0);
	
	test_results();
	
	return did_no_test_fail() ? EXIT_SUCCESS : EXIT_FAILURE;
}

