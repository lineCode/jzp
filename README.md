# twexif

Twitter will strip out metadata from your JPG image file when posted on its platform.

*twexif* is a simple command line tool allows you to insert tiny files / metadata (up to 10KB)
into your image file (jpg) which Twitter will preserve.

To maximise the amount of data you can embed, compress your file(s) into a ZIP archive.

*(If you want to embed more data into an image file for Twitter (up to 5MB) then please use [pdvzip](https://github.com/CleasbyCode/pdvzip)  (PNG only)).*

*twexif* works on Linux and Windows.  

**Video Demos**  

* [***Windows Example***](https://youtu.be/vrb-cRl34LI)
* [***Linux Example***](https://youtu.be/jAH-Ru3l57o)
  
Compile and run the program under Windows or **Linux**  

## Usage (Linux Example)

```c

$ g++ twexif.cpp -s -o twexif
$
$ ./twexif

Usage:  twexif <jpg-image>  <zip_file>
        twexif --info

$ ./twexif  image.jpg  my_source_code.zip

 Created output file: "twexif_img.jpg 199856 Bytes"
 You can now tweet this image.

$

```
To get access to and extract your embedded data file(s) using Linux, just rename the *.jpg* file extension to *.zip* and
from the Linux Desktop, click the file icon to open/extract the ZIP contents. 

Second Linux option. From the terminal, use the commands:

```c 
 $ zip -FF your_image.jpg --out extract.zip
 $ unzip extract.zip
```

Third Linux option, if you have problems with the second option.

```c
 $ 7z e your_image.jpg
```

From Windows, first rename the *.jpg* file extension to *.zip*, then from a Windows console type the command: 
```c
 PS C:\Demo> Expand-Archive  your_image.zip 
```

My other programs you may find useful:-  

* [pdvzip - PNG Data Vehicle (ZIP Edition) for Compatible Social Media & Image Hosting Sites.](https://github.com/CleasbyCode/pdvzip)  
* [jdvrif - JPG Data Vehicle for Reddit, Imgur, Flickr & Other Compatible Social Media / Image Hosting Sites.](https://github.com/CleasbyCode/jdvrif)
* [pdvrdt - PNG Data Vehicle for Reddit](https://github.com/CleasbyCode/pdvrdt)  
* [pdvps - PNG Data Vehicle for Twitter, PowerShell Edition](https://github.com/CleasbyCode/pdvps)   

##

