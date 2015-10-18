<?hh //strict

/**
 * This file is part of hhpack\file package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\file;

use \Generator;

final class ParsedFileReader<T>
{

    private FileReader $reader;

    public function __construct(FileReader $reader)
    {
        $this->reader = $reader;
    }

    public static function fromString(string $filePath) : ParsedFileReader<T>
    {
        $reader = FileReader::fromString($filePath);
        return new self($reader);
    }

    public function records(ParseSpecification<T> $spec) : Generator<int, T, void>
    {
        foreach ($this->reader->lines() as $line) {
            yield $spec->parse($line);
        }
    }

    public function close() : void
    {
        $this->reader->close();
    }

}
