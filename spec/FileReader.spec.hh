<?hh //partial

use minimalist\file\File;
use minimalist\file\FileReader;

describe('FileReader', function() {
    beforeEach(function() {
        $this->path = realpath(__DIR__ . '/fixtures/text.log');
        $this->reader = FileReader::fromString($this->path);
    });
    describe('#fromString()', function() {
        it('return file reader', function() {
            expect($this->reader)->toBeAnInstanceOf(FileReader::class);
        });
    });
    describe('#readBytes()', function() {
        beforeEach(function() {
            $concatValue = '';
            $chunkValues = $this->reader->readBytes(6);

            foreach ($chunkValues as $chunkValue) {
                $concatValue .= (string) $chunkValue;
            }
            $this->concatValue = $concatValue;
        });
        it('return Continuation<ReadedChunk>', function() {
            expect($this->concatValue)->toBe("1,foo\n2,bar\n3,foo\n4,bar\n");
        });
    });

    describe('#readRecords()', function() {
        beforeEach(function() {
            $concatValue = '';
            $records = $this->reader->readRecords();

            foreach ($records as $record) {
                $concatValue .= (string) $record;
            }
            $this->concatValue = $concatValue;
        });
        it('return Continuation<ReadedRecord>', function() {
            expect($this->concatValue)->toBe("1,foo2,bar3,foo4,bar");
        });
    });

    describe('#readedLength()', function() {
        beforeEach(function() {
            $records = $this->reader->readRecords();
            foreach ($records as $record) {}
        });
        it('return Continuation<ReadedRecord>', function() {
            expect($this->reader->readedLength())->toBe($this->reader->totalSize());
        });
    });

});
