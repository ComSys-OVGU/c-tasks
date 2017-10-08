The rawdata files are from an imaginary image sensor with a resolution of 5400x3600.

Try to convert these raw data files to a colored bitmap file!
If you did it right, you can open the image with your regular viewer 
or open it in paint or photoshop. Also try to create it as fast as possible. 
Simple implementations may take more than ten seconds, effective ones need less than a second.
You may also try to create a jpeg or png file. But better use libraries for these ;)

The three files contain the red, green and blue parts, respectively. 
Each pixel's color value is of 8 bit depth.
First pixel is at the bottom left, and pixels are stored line by line
in the raw files. The files contain no other information than the raw pixels,
i.e. they are each exactly 5400x3600x1 Bytes in size.