<?hh //partial

require_once __DIR__ . '/../../vendor/autoload.php';

use hhpack\file\ParsedFileReader;
use hhpack\file\example\CustomRecordSpecification;

$spec = new CustomRecordSpecification();
$reader = ParsedFileReader::fromString(__DIR__ . '/example.csv');

foreach ($reader->records($spec) as $record) {
    echo $record->getName(), "\n";
    echo $record->getDescription(), "\n";
}

$reader->close();
