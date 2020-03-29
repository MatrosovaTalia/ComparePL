import "dart:io";

void main() {
  File myFile = new File("array.txt");
  String myFileContent = myFile.readAsStringSync();
  List<String> mylist = myFileContent.split(' ');
  var arr = [];
  var L = mylist.length;
  for (var i = 0; i < L; i++) arr.add(int.parse(mylist[i]));

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
  print(stopwatch.elapsedMicroseconds); // executing time in microseconds
}
