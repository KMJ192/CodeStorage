use std::cell::RefCell;
use std::rc::Rc;

#[derive(Debug)]
struct DataContainer {
  data: Rc<RefCell<String>>,
}

pub fn rc_refcell() {
  let important_data = Rc::new(RefCell::new("Super duper important data".to_string()));

  let container_1 = DataContainer {
    data: Rc::clone(&important_data),
  };

  let mut container_2 = DataContainer {
    data: Rc::clone(&important_data),
  };

  for _ in 0..10 {
    container_1.data.borrow_mut().push('a');
    container_2.data.borrow_mut().push('b');
  }
  
  println!("{container_1:?}\n{container_2:?}\n{important_data:?}");
}