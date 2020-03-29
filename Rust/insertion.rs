use std::time::{Instant};

fn main() {
	let mut vec = vec![10, 20, 3, 6, 1, 0];
	let L = vec.len();

	// for x in &vec {
	// 	print!("{} ", x);
	// }

	let start = Instant::now();
	for i in 1..L{
		let mut j = i;
		let buf = vec[i];
		while(j > 0 && vec[j-1] > buf){
			vec[j] = vec[j-1];
			j -= 1;
		}
		vec[j] = buf;
	}
	let duration = start.elapsed();

	// println!("");
	// for x in &vec {
	// 	print!("{} ", x);
	// }

	println!("{:?}", duration);
}
