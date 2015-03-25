file
======================================================

[![Build Status](https://travis-ci.org/minimalist-jr/file.svg?branch=master)](https://travis-ci.org/minimalist-jr/file)

This package is a library for performing a simple to file operations hacklang.  
Will provide a lightweight and simple api to the user.


Basic usage
------------------------------------------------------

Read processing of files can be realized by a simple code as follows.

### Reading one line at a time.


```hack
$reader = FileReader::fromString('/path/to/text.log');

foreach ($reader->readRecords() as $readRecord) {
	echo $reader->readedSize(), "\n"; //output readed size
	echo $readRecord->length(), "\n"; //output length
	echo $readRecord->value(), "\n"; //output content
};

$reader->close();
```

### Reading every few bytes.


```hack
$reader = FileReader::fromString('/path/to/text.log');

foreach ($reader->readBytes(100) as $readChunk) {
	echo $reader->readedSize(), "\n"; //output readed size
	echo $readRecord->length(), "\n"; //output length
	echo $readRecord->value(), "\n"; //output content
};

$reader->close();
```
