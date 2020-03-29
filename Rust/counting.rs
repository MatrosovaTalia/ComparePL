use std::time::{Instant};

fn main() {
	let mut vec = vec![10, 20, 3, 6, 1, 0];
	let L = vec.len();

	// for x in &vec {
	// 	print!("{} ", x);
	// }

	let start = Instant::now();
	let mut max = vec[0];
	for i in 1..L {
		if vec[i] > max{
			max = vec[i];
		}
	}
	let mut cv = vec![0; max + 1];
	for i in 0..L {
		cv[vec[i]] = cv[vec[i]] + 1 ;
	}
	for i in 1..max + 1 {
		cv[i] = cv[i] + cv[i - 1];
	}
	let mut result = vec![0; L];
	for i in 0..L {
		result[cv[vec[i]] - 1] = vec[i];
		cv[vec[i]] = cv[vec[i]] - 1;
	}
	let duration = start.elapsed();

	// println!("");
	// for x in &result {
	// 	print!("{} ", x);
	// }

	println!("{:?}", duration);
}