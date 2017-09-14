<?hh //partial

require_once __DIR__.'/../../vendor/autoload.php';

use HHPack\File\FileLineStream;
use HHPack\File\ParsedChunkStream;
use HHPack\File\example\CustomRecordSpecification;

$spec = new CustomRecordSpecification();

$lines = FileLineStream::fromString(__DIR__.'/example.csv');
$stream = new ParsedChunkStream($lines, $spec);

foreach ($stream as $record) {
  echo $record->getName(), "\n";
  echo $record->getDescription(), "\n";
}
