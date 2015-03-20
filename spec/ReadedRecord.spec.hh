<?hh //partial

use bookman\reader\ReadedRecord;

describe('ReadedRecord', function() {
    beforeEach(function() {
        $this->record = new ReadedRecord('hello');
    });
    describe('#length()', function() {
        it('return length', function() {
            expect($this->record->length())->toEqual(5);
        });
    });
    describe('#value()', function() {
        it('return value', function() {
            expect($this->record->value())->toEqual('hello');
        });
    });
    describe('#substring()', function() {
        it('return substring value', function() {
            expect($this->record->substring(0, 3))->toEqual('hel');
        });
    });
    describe('#match()', function() {
        context('when match pattern', function() {
            it('return true', function() {
                expect($this->record->match('/^hel/'))->toBeTrue();
            });
        });
        context('when unmatch pattern', function() {
            it('return false', function() {
                expect($this->record->match('/foo/'))->toBeFalse();
            });
        });
    });
    describe('#split()', function() {
        beforeEach(function() {
            $this->values = $this->record->split('e');
        });
        it('return split value', function() {
            expect($this->values)->toBeAn('array');
            expect($this->values)->toHaveLength(2);
        });
    });
});
