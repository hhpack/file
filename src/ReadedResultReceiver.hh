<?hh //strict

namespace bookman;

interface ReadedResultReceiver
{
    public function receiveResult(ReadedResult $result) : void;
}
