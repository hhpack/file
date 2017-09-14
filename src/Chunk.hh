<?hh //strict

/**
 * This file is part of hhpack\file package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\File;

class Chunk implements ReadedResult {

  public function __construct(private string $content) {}

  public function length(): int {
    return strlen($this->content);
  }

  <<__Memoize>>
  public function value(): string {
    return str_replace(["\r", "\n"], ['', ''], $this->content);
  }

  public function raw(): string {
    return $this->content;
  }

  public function substring(int $startAt, int $length): string {
    return substr($this->content, $startAt, $length);
  }

  public function match(string $pattern): bool {
    return preg_match($pattern, $this->content) === 1;
  }

  public function split(string $keyword): array<string> {
    return explode($keyword, $this->content);
  }

  public function isEmpty(): bool {
    return $this->length() <= 0;
  }

  public function sendTo(ReadedResultReceiver $receiver): void {
    $receiver->receiveResult($this);
  }

  public function __toString(): string {
    return $this->value();
  }

  public static function fromString(string $value): Chunk {
    return new Chunk($value);
  }

}
