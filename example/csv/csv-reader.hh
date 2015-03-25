<?hh //partial

require_once __DIR__ . '/../../vendor/autoload.php';

use minimalist\file\reader\SeparatedFileReader;
use minimalist\file\reader\ColumnSpecification;

$spec = new ColumnSpecification();
$spec->addColumn(0, 'name');
$spec->addColumn(1, 'description');

$reader = SeparatedFileReader::fromString(__DIR__ . '/example.csv');

foreach ($reader->readRecords($spec) as $record) {
    echo $record->get('name'), "\n";
    echo $record->get('description'), "\n";
}

$reader->close();
