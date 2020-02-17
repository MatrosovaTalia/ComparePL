use std::time::{Instant};

fn main() {
	let mut vec = vec![10, 20, 3, 6, 1, 0];
	let L = vec.len();

	for x in &vec {
		print!("{} ", x);
	}

	let start = Instant::now();
	vec = merge(vec.clone());
	let duration = start.elapsed();

	println!("");
	for x in &vec {
		print!("{} ", x);
	}

	println!("\nTime elapsed in expensive_function() is: {:?}", duration);
}

fn merge(mut vec: Vec<i32>) -> Vec<i32>{
	if(vec.len() > 1){
		let mut v1 = vec![];
		let mut v2 = vec![];
		for i in 0..vec.len(){
			if(i < vec.len() / 2){
				v1.push(vec[i])
			}
			else{
				v2.push(vec[i])
			}
		}
		v1 = merge(v1);
		v2 = merge(v2);
		let mut i = 0;
		let mut j = 0;
		let mut k = 0;
		while(i < v1.len() && j < v2.len()){
			if(v1[i] < v2[j]){
				vec[k] = v1[i];
				i += 1;
			}
			else{
				vec[k] = v2[j];
				j += 1;
			}
			k += 1;
		}
		while(i < v1.len()){
			vec[k] = v1[i];
			i += 1;
			k += 1;
		}
		while(j < v2.len()){
			vec[k] = v2[j];
			j += 1;
			k += 1;
		}
	}
	return vec;
}