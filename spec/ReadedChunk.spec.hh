<?hh //partial

use bookman\ReadedChunk;

describe('ReadedChunk', function() {
    beforeEach(function() {
        $this->chunk = new ReadedChunk('hello');
    });
    describe('#length()', function() {
        it('return length', function() {
            expect($this->chunk->length())->toEqual(5);
        });
    });
});
