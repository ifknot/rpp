# R++
Statistical software tools inspired by R and written in C++

![scrabble_data](https://cldup.com/dRGROyJWj7.jpg)

An R *inspired* statistical software toolkit of data types and functions written in C++.

Designed to offer *familiar enough* semantics with their R language counterparts to facilitate R knowledge and skills transfer into the C++ domain.
My blog page [libfbp.blogspot.com](http://libfbp.blogspot.com/2020/09/a-heterogeneous-data-frame-in-c.html)
## R-ish types and functions so far:
|structures | | | | | |
|----------------	|---------------	|--------------	|---------------	|----------------	|-------------------	|
|[x] vector       |[x] variant      |[x] data_frame |[x] list         |[ ] matrix       |[ ]                  |

|types | | | | | |
|----------------	|---------------	|--------------	|---------------	|----------------	|-------------------	|
|[x] complex      |[ ]              |[ ]            |[ ]              |[ ]              |[ ]                  |
|[x] date         |[ ] POSIXct      |[ ] POSIXlt   |[ ]              |[ ]              |[ ]                  |

| |functions| | | | | |
|---------------- |----------------	|---------------	|--------------	|---------------	|----------------	|-------------------	|
|a|[x] as_dates    |[ ]              |[ ]            |[ ]              |[ ]              |[ ]                  |
|b|[ ]             |[ ]              |[ ]            |[ ]              |[ ]              |[ ]                  |
|c|[ ]             |[ ]              |[ ] colnames   |[ ]              |[ ]              |[ ]                  |
|f|[x] factor      |[x] floor        |[ ]            |[ ]              |[ ]              |[ ]                  |
|h|[x] head        |[ ]              |[ ]            |[ ]              |[ ]              |[ ]                  |
|m|[x] match       |[x] match_all    |[ ]            |[ ]              |[ ]              |[ ]                  |
|n|[x] names       |[ ] ncol         |[ ] nrow       |[ ]              |[ ]              |[ ]                  |
|r|[x] range       |[x] read_csv     |[x] rescale    |[ ]              |[ ]              |[ ]                  |
|s|[x] sort        |[ ] split        |[ ]            |[ ]              |[ ]              |[ ]                  |
|t|[x] tail        |[ ]              |[ ]            |[ ]              |[ ]              |[ ]                  |
|u|[x] unique      |[ ]              |[ ]            |[ ]              |[ ]              |[ ]                  |
## example usage
main.cpp is your best place at the moment
