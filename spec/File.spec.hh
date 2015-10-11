<?hh //partial

use hhpack\file\File;
use hhpack\file\FileMode;
use hhpack\file\FileNotFoundException;


describe('File', function() {
    beforeEach(function() {
        $this->path = realpath(__DIR__ . '/fixtures/text.log');
        $this->file = File::fromString($this->path);
    });
    describe('#open()', function() {
        beforeEach(function() {
            $this->file->open(FileMode::READ_ONLY);
        });
        it('open file', function() {
            expect($this->file->isOpened())->toBeTrue();
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
            $this->file->open(FileMode::READ_ONLY);
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
            $this->file->open(FileMode::READ_ONLY);
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
