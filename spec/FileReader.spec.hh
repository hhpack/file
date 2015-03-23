<?hh //partial

use minimalist\file\File;
use minimalist\file\FileReader;

describe('FileReader', function() {
    describe('#fromString()', function() {
        beforeEach(function() {
            $this->path = realpath(__DIR__ . '/fixtures/text.log');
            $this->reader = FileReader::fromString($this->path);
        });
        it('return file reader', function() {
            expect($this->reader)->toBeAnInstanceOf(FileReader::class);
        });
    });
});
