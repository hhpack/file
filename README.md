file
======================================================

[![Latest Stable Version](https://poser.pugx.org/hhpack/file/v/stable)](https://packagist.org/packages/hhpack/file)
[![Build Status](https://travis-ci.org/hhpack/file.svg?branch=master)](https://travis-ci.org/hhpack/file)
[![Dependency Status](https://www.versioneye.com/user/projects/56239db636d0ab0016000be8/badge.svg?style=flat)](https://www.versioneye.com/user/projects/56239db636d0ab0016000be8)
[![License](https://poser.pugx.org/hhpack/file/license)](https://packagist.org/packages/hhpack/file)

This package is a library for performing a simple to file operations hacklang.  
Will provide a lightweight and simple api to the user.


Basic usage
------------------------------------------------------

Read processing of files can be realized by a simple code as follows.

### Reading one line at a time.

```hack
use hhpack\file\FileReader;

$reader = FileReader::fromString('/path/to/text.log');

foreach ($reader->lines() as $line) {
	echo $line->length(), "\n"; //output length
	echo $line->value(), "\n"; //output content
};

$reader->close();
```

### Reading every few bytes.

```hack
use hhpack\file\FileReader;

$reader = FileReader::fromString('/path/to/text.log');

foreach ($reader->bytes(100) as $chunk) {
	echo $chunk->length(), "\n"; //output length
	echo $chunk->value(), "\n"; //output content
};

$reader->close();
```

Read the CSV file
------------------------------------------------------

```hack
use hhpack\file\SeparatedFileReader;
use hhpack\file\ColumnSpecification;

$spec = new ColumnSpecification(',', '"');
$spec->addColumn(0, 'name');
$spec->addColumn(1, 'description');

$reader = SeparatedFileReader::fromString(__DIR__ . '/example.csv');

foreach ($reader->records($spec) as $record) {
    echo $record->get('name'), "\n";
    echo $record->get('description'), "\n";
}

$reader->close();
```

Customizing the reading of the record
------------------------------------------------------

Will create a parser that implements the **ParseSpecification**.  
Then use the **ParsedFileReader**, and then apply the parser.

```hack
use hhpack\file\ParsedFileReader;
use hhpack\file\ParseSpecification;

final class CustomRecordSpecification implements ParseSpecification<array<string>>
{
    public function parse(Chunk $line) : array<string>
    {
        return $line->split(',');
    }
}

$spec = new CustomRecordSpecification();
$reader = ParsedFileReader::fromString(__DIR__ . '/example.csv');

foreach ($reader->records($spec) as $values) {
    echo $values[0], "\n";
    echo $values[1], "\n";
}

$reader->close();
```

Run the test
------------------------------------------------

You can run the test with the following command.

	composer install
	composer test
