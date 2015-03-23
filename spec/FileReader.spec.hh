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

    describe('#readedSize()', function() {
        beforeEach(function() {
            $progressSizes = [];
            $records = $this->reader->readRecords();

            foreach ($records as $record) {
                $progressSizes[] = $this->reader->readedSize();
            }
            $progressSizes[] = $this->reader->readedSize();
            $this->progressSizes = $progressSizes;
        });
        it('return Continuation<ReadedRecord>', function() {
            expect($this->progressSizes[0])->toBe(6);
            expect($this->progressSizes[1])->toBe(12);
            expect($this->progressSizes[2])->toBe(18);
            expect($this->progressSizes[3])->toBe(24);
            expect($this->progressSizes[4])->toBe($this->reader->totalSize());
        });
    });

});
