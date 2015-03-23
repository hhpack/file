<?hh //strict

namespace minimalist\file;

class ReadedRecord implements ReadedResult
{

    use Chunk;

    public function __construct (
        private string $content
    )
    {
    }

}
