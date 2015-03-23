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

    describe('#readBytes()', function() {
        beforeEach(function() {
            $this->path = realpath(__DIR__ . '/fixtures/text.log');
            $this->reader = FileReader::fromString($this->path);
            $chunkValues = $this->reader->readBytes(6);

            $concatValue = '';

            foreach ($chunkValues as $chunkValue) {
                $concatValue .= (string) $chunkValue;
            }
            $this->concatValue = $concatValue;
        });
        it('return Continuation<ReadedChunk>', function() {
            expect($this->concatValue)->toBe("1,foo\n2,bar\n3,foo\n4,bar\n");
        });
    });

});
