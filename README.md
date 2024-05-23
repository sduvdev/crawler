# Koogle Crawler

## Overview

This project is a simple web crawler implemented in C++. It uses the following components:
- `Downloader`: Downloads web pages.
- `LinkExtractor`: Extracts links from HTML content.
- `Indexer`: Indexes the content of web pages for search functionality.
- `Crawler`: Coordinates the downloading, link extraction, and indexing of web pages.

## Building the Project

To build the project, navigate to the `crawler` directory and run `make`:
```
cd /koogle-project/crawler
make
```


## Running the Project

To run the project, execute the compiled binary:
```
./bin/crawler
```


## Directory Structure

```
crawler/
├── bin
│   └── crawler
├── class_diagram.md
├── inc
│   ├── Crawler.h
│   ├── Downloader.h
│   ├── IDownloader.h
│   ├── ILinkExtractor.h
│   ├── Indexer.h
│   └── LinkExtractor.h
├── main.cpp
├── Makefile
├── obj
│   ├── Crawler.o
│   ├── Downloader.o
│   ├── Indexer.o
│   ├── LinkExtractor.o
│   └── main.o
├── README.md
├── src
│   ├── Crawler.cpp
│   ├── Downloader.cpp
│   ├── Indexer.cpp
│   └── LinkExtractor.cpp
└── TODO.md


```

## Dependencies

libcurl: For downloading web pages.    
libgumbo: For parsing HTML content.

