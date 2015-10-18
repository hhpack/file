<?hh //partial

require_once __DIR__ . '/../../vendor/autoload.php';

use hhpack\file\SeparatedFileReader;
use hhpack\file\ColumnSpecification;

$spec = new ColumnSpecification();
$spec->addColumn(0, 'name');
$spec->addColumn(1, 'description');

$reader = SeparatedFileReader::fromString(__DIR__ . '/example.csv');

foreach ($reader->records($spec) as $record) {
    echo $record->get('name'), "\n";
    echo $record->get('description'), "\n";
}

$reader->close();
