# ddepth

`ddepth` means desired depth of the destination image

It has information about what kinds of data stored in an image, and that can be unsigned char (`CV_8U`), signed char (`CV_8S`), unsigned short (`CV_16U`), and so on...

# type

As for type, the type has information combined from 2 values: 

**image depth** + **the number of channels**. 

It can be for example `CV_8UC1` (which is equal to `CV_8U`), `CV_8UC2`, `CV_8UC3`, `CV_8SC1` (which is equal to `CV_8S`) etc.

# Further Readings

For more discussion, it can be found in the following two articles

* [image type vs image depth](http://answers.opencv.org/question/4783/image-type-vs-image-depth/)
* [Matrix depth equals 0](http://answers.opencv.org/question/742/matrix-depth-equals-0/#747)
* [Detailed - Fixed Pixel Types. Limited Use of Templates](http://docs.opencv.org/2.4/modules/core/doc/intro.html#fixed-pixel-types-limited-use-of-templates)

You can see in the [doc](http://docs.opencv.org/master/d4/d86/group__imgproc__filter.html#ga27c049795ce870216ddfb366086b5a04) that `ddepth` stands for _"Destination depth"_, which is the depth of result (destination) image.

If you use `-1`, the result (destination) image will have the same depth as the input (source) image.