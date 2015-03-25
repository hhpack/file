<?hh //partial

use minimalist\file\Chunk;
use minimalist\file\reader\ColumnSpecification;

describe('ColumnSpecification', function() {
    beforeEach(function() {
        $spec = new ColumnSpecification();
        $spec->addColumn(0, 'name');
        $spec->addColumn(1, 'title');

        $this->spec = $spec;
        $this->record = new Chunk('"foo","bar \" bar"');
    });
    describe('#parse()', function() {
        it('return minimalist\file\reader\SeparatedRecord ', function() {
            $result = $this->spec->parse($this->record);
            expect($result->get('name'))->toBe('foo');
            expect($result->get('title'))->toBe('bar \" bar');
        });
    });
});