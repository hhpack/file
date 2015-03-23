file
======================================================

[![Build Status](https://travis-ci.org/minimalist-jr/file.svg?branch=master)](https://travis-ci.org/minimalist-jr/file)



Basic usage
------------------------------------------------------


```hack
$reader = FileReader::fromString('/path/to/text.log');

foreach ($reader->readRecords() as $readRecord) {
	echo $readRecord->length(); //outout length
	echo $readRecord->value(); //outout content
};

$reader->close();
```

or


```hack
$reader = FileReader::fromString('/path/to/text.log');

foreach ($reader->readBytes(100) as $readChunk) {
	echo $readRecord->length(); //outout length
	echo $readRecord->value(); //outout content
};

$reader->close();
```
