void main() {
  var arr = [10, 20, 3, 6, 1, 0];
  var L = arr.length;

  print(arr);

  Stopwatch stopwatch = new Stopwatch()..start();
  var max = arr[0];
  for (var i = 1; i < L; i++) {
    if (arr[i] > max) max = arr[i];
  }
  var cv = [];
  for (var i = 0; i < max + 1; i++) cv.add(0);
  for (var i = 0; i < L; i++) {
    cv[arr[i]] += 1;
  }
  for (var i = 1; i < max + 1; i++) {
    cv[i] = cv[i] + cv[i - 1];
  }
  var result = [];
  for (var i = 0; i < L; i++) result.add(0);
  for (var i = 0; i < L; i++) {
    result[cv[arr[i]] - 1] = arr[i];
    cv[arr[i]] -= 1;
  }
  print('Sort executed in ${stopwatch.elapsed}');
  
  print(result);
}
