<?hh //strict

namespace HHPack\File\Example;

use HHPack\File\Chunk;
use HHPack\File\ParseSpecification;

final class CustomRecordSpecification
  implements ParseSpecification<CustomRecord> {

  public function parse(Chunk $line): CustomRecord {
    $values = $line->split(',');
    return new CustomRecord(trim($values[0]), trim($values[1]));
  }

}
