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

    public function __construct(
        FileReader $reader,
        ColumnSpecification $spec
    )
    {
        $this->reader = new ParsedFileReader($reader, $spec);
    }

    public function records() : Iterator<SeparatedRecord>
    {
        return $this->reader->records();
    }

    public function close() : void
    {
        $this->reader->close();
    }

}
