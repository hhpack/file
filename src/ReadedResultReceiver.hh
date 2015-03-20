<?hh //strict

namespace bookman\reader;

interface ReadedResultReceiver
{
    public function receiveResult(ReadedResult $result) : void;
}
