<?hh //strict

namespace HHPack\File\Test;

use HHPack\File\File;
use HackPack\HackUnit\Contract\Assert;

final class FileTest {
  <<Test>>
  public function create(Assert $assert): void {
    $path = realpath(__DIR__.'/fixtures/text.log');
    $file = File::fromString($path);

    $assert->string($file->getName())->is('text.log');
    $assert->string($file->getPath())->is($path);
    $assert->bool($file->exists())->is(true);
  }
}
