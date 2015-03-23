<?hh //partial

use minimalist\file\File;
use minimalist\file\FileNotFoundException;

describe('File', function() {
    beforeEach(function() {
        $this->path = realpath(__DIR__ . '/fixtures/text.log');
        $this->file = File::fromString($this->path);
    });
    describe('#__construct()', function() {
        context('when file not exists', function() {
            it('throw FileNotFoundException', function() {
                expect(function() {
                    (new File('not_found.txt'));
                })->toThrow(FileNotFoundException::class);
            });
        });
    });
    describe('#getName()', function() {
        it('return file name', function() {
            expect($this->file->getName())->toEqual('text.log');
        });
    });
    describe('#getPath()', function() {
        it('return file path', function() {
            expect($this->file->getPath())->toEqual($this->path);
        });
    });
    describe('#readBytes()', function() {
        beforeEach(function() {
            $this->chunk = $this->file->readBytes(3);
        });
        it('return read chunk', function() {
            expect($this->chunk->value())->toEqual('1,f');
        });
    });
    describe('#readRecord()', function() {
        beforeEach(function() {
            $this->path = realpath(__DIR__ . '/fixtures/text.log');
            $this->file = File::fromString($this->path);
            $this->record = $this->file->readRecord();
        });
        it('return read record', function() {
            expect($this->record->value())->toEqual('1,foo');
        });
    });
    describe('#exists()', function() {
        context('when file exists', function() {
            it('return true', function() {
                expect($this->file->exists())->toBeTrue();
            });
        });
    });
});
