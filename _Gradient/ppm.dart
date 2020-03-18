void fillGradientLine(arr, line, w, a, b){
  var delta = b - a;
	var offset = line * w;
	for(var i = 0; i < w; i++){
		var fraction = i / w;
		arr[offset + i] = a + (delta * fraction).floor();
	}
}

List generateGrayGradient(h, w, a, b){
  var size = h * w;
  var arr = [];
  for(var i = 0; i < size; i++) arr.add(0);
  for(var i = 0; i < h; i++) fillGradientLine(arr, i, w, a, b);
  return arr;
}

void saveGradient(arr, h, w, b){
	print("P2\n$w $h\n$b");
	for(var i = 0; i < h; i++){
    var str = "";
		for(var j = 0; j < w; j++){
			str += arr[i * w + j].toString() + " ";
		}
		print(str);
	}
}

void main() {
  var h = 10;
	var w = 10;
  var a = 55;
	var b = 233;
  var arr = generateGrayGradient(h, w, a, b);
	saveGradient(arr, h, w, b);
}