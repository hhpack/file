<?hh //partial

require_once __DIR__ . '/../../vendor/autoload.php';

use HHPack\File\FileLineStream;
use HHPack\File\SeparatedRecordStream;
use HHPack\File\ColumnSpecification;

$spec = new ColumnSpecification();
$spec->addColumn(0, 'name');
$spec->addColumn(1, 'description');

$lines = FileLineStream::fromString(__DIR__ . '/example.csv');
$stream = new SeparatedRecordStream($lines, $spec);

foreach ($stream as $record) {
    echo $record->get('name'), "\n";
    echo $record->get('description'), "\n";
}
