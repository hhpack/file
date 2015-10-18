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


final class SeparatedFileReader
{

    private ParsedFileReader<SeparatedRecord> $reader;

    public function __construct(FileReader $reader)
    {
        $this->reader = new ParsedFileReader($reader);
    }

    public static function fromString(string $filePath) : SeparatedFileReader
    {
        $reader = FileReader::fromString($filePath);
        return new self($reader);
    }

    public function records(ColumnSpecification $spec) : Generator<int, SeparatedRecord, void>
    {
        return $this->reader->records($spec);
    }

    public function close() : void
    {
        $this->reader->close();
    }

}
