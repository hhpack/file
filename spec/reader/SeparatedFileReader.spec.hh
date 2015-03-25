<?hh //partial

use minimalist\file\File;
use minimalist\file\reader\ColumnSpecification;
use minimalist\file\reader\SeparatedFileReader;


describe('SeparatedFileReader', function() {
    beforeEach(function() {
        $spec = new ColumnSpecification();
        $spec->addColumn(0, 'name');
        $spec->addColumn(1, 'title');

        $this->spec = $spec;
        $this->path = realpath(__DIR__ . '/../fixtures/text.csv');
        $this->reader = SeparatedFileReader::fromString($this->path);
    });
    describe('#fromString()', function() {
        it('return file reader', function() {
            expect($this->reader)->toBeAnInstanceOf(SeparatedFileReader::class);
        });
    });
    describe('#readRecords()', function() {
        beforeEach(function() {
            $concatValue = '';
            $records = $this->reader->readRecords($this->spec);

            foreach ($records as $record) {
                $concatValue .= (string) $record->get('name');
                $concatValue .= (string) $record->get('title');
            }
            $this->concatValue = $concatValue;
        });
        it('return Generator<int, SeparatedRecord, void>', function() {
            expect($this->concatValue)->toBe("foo1bar1foo2bar2");
        });
    });

});
