<?hh //strict

namespace hhpack\file\example;

use hhpack\file\Chunk;
use hhpack\file\ParseSpecification;

final class CustomRecordSpecification implements ParseSpecification<CustomRecord>
{

    public function parse(Chunk $line) : CustomRecord
    {
        $values = $line->split(',');
        return new CustomRecord(trim($values[0]), trim($values[1]));
    }

}
