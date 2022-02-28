# LZCopy commandline tool
This tool provides a simple mechanisms for uncompressing files compressed with LZSS compression. It uses the `lzexpand` Windows API library, and passes the filenames you input straight into a call to `LZCopy` 

## Usage
`.\LZCopy.exe compressed_file uncompressed_file`

or

``.\LZCopy.exe compressed_file` _this will default the output file to out.bin_

## Disclaimer
I basically made this to decompress a single file and understand the LZ Expand API. It sees no evil, hears no evil, speaks no evil. Use with care as I literally catch no errors.

If you do wish to modify, the decompress function does return some errors values that you can use to make a bit more of a refined tool.

## Build
This should be buildable within any standard visual studio setup. Lz32.lib was required as an additional dependency, so bare that in mind if you use a different build tool.
