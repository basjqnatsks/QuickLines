use std::fs;
use std::time::Instant;

fn main() {
    let now = Instant::now();
    let data = fs::read_to_string("words.txt").expect("Unable to read file");
    let mut _lines = 0;
    for c in data.chars() { 
        match c {
            '\n' => _lines += 1,
            _ => ()
        };
    }
    let completion_time = now.elapsed().as_millis();
    println!("Time: {completion_time}ms");
}