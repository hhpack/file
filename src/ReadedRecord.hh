<?hh //strict

namespace bookman\reader;

class ReadedRecord implements ReadedResult
{

    use Chunk;

    public function __construct (
        private string $content
    )
    {
    }

}
