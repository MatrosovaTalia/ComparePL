void main() {
  var arr = [10, 20, 3, 6, 1, 0];
  var L = arr.length;

  print(arr);

  Stopwatch stopwatch = new Stopwatch()..start();
  for (var i = 1; i < L; i++) {
    var j = i;
    var buf = arr[i];
    while (j > 0 && arr[j - 1] > buf) {
      arr[j] = arr[j - 1];
      j -= 1;
    }
    arr[j] = buf;
  }
  print('Sort executed in ${stopwatch.elapsed}');

  print(arr);
}
