file
======================================================

[![Build Status](https://travis-ci.org/hhpack/file.svg?branch=master)](https://travis-ci.org/hhpack/file)

This package is a library for performing a simple to file operations hacklang.  
Will provide a lightweight and simple api to the user.


Basic usage
------------------------------------------------------

Read processing of files can be realized by a simple code as follows.

### Reading one line at a time.


```hack
$reader = FileReader::fromString('/path/to/text.log');

foreach ($reader->lines() as $line) {
	echo $reader->readedSize(), "\n"; //output readed size
	echo $line->length(), "\n"; //output length
	echo $line->value(), "\n"; //output content
};

$reader->close();
```

### Reading every few bytes.


```hack
$reader = FileReader::fromString('/path/to/text.log');

foreach ($reader->bytes(100) as $chunk) {
	echo $reader->readedSize(), "\n"; //output readed size
	echo $chunk->length(), "\n"; //output length
	echo $chunk->value(), "\n"; //output content
};

$reader->close();
```
