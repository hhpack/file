<?hh //partial

use minimalist\file\ReadedChunk;

describe('ReadedChunk', function() {
    beforeEach(function() {
        $this->chunk = new ReadedChunk('hello');
    });
    describe('#length()', function() {
        it('return length', function() {
            expect($this->chunk->length())->toEqual(5);
        });
    });
    describe('#value()', function() {
        it('return value', function() {
           expect($this->chunk->value())->toEqual('hello');
        });
    });
    describe('#substring()', function() {
        it('return substring value', function() {
           expect($this->chunk->substring(0, 3))->toEqual('hel');
        });
    });
    describe('#match()', function() {
        context('when match pattern', function() {
            it('return true', function() {
                expect($this->chunk->match('/^hel/'))->toBeTrue();
            });
        });
        context('when unmatch pattern', function() {
            it('return false', function() {
                expect($this->chunk->match('/foo/'))->toBeFalse();
            });
        });
    });
    describe('#split()', function() {
        beforeEach(function() {
            $this->values = $this->chunk->split('e');
        });
        it('return split value', function() {
            expect($this->values)->toBeAn('array');
            expect($this->values)->toHaveLength(2);
        });
    });
});
