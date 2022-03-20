/**
  상태 패턴 (state pattern)
  상태 객체들의 집합로 표현되는 일종의 내부상태를 가지며, 이 값의 동작은 내부 상태에 기반하여 바뀜.
  상태 객체들은 기능을 공유, 
  러스트에서는 객체와 상속보다 구조체와 트레잇을 사용함.
  각 상태 객체는 자신의 동작 및 다른 상태로 변경되어야 할 때의 제어에 대한 책임이 있다.
  상태 객체를 보유한 값은 상태들의 서로 다른 행동 혹은 상태간의 전이가 이뤄지는 때에 대하여 아무것도 모름

  상태 패턴을 사용한다는 것은 프로그램의 사업적 요구사항들이 변경될 때, 상태를 보유한 값의 코드 혹은 그 값을
  사용하는 코드는 변경될 필요가 없음을 의미함.

  블로그에 게시물을 올리는 작업 흐름을 구현하고자 한다.
  블로그의 최종 기능은 다음과 같음
  1. 블로그 게시물은 빈 초안으로 시작
  2. 초안이 완료되면 게시물의 검토가 요청됨.
  3. 게시물의 승인되면 게시됨.
  4. 오직 게시된 블로그 게시물만이 출력될 내용물을 반환하므로, 승인되지 않은 게시물은 실수로라도 게시될 수 없음
  이 외의 게시물에 시도되는 어떠한 변경 사항도 영향을 미쳐서는 안됨.
  리뷰를 요청하기도 전에 블로그 게시물 초안을 승인하려는 시도를 했다면, 그 게시물은 비공게 초안인 상태로 유지되어야 함.
*/

// 블로그 크레이트
pub struct Post {
  state: Option<Box<dyn State>>,
  content: String,
}

pub struct DraftPost {
  content: String,
}

impl Post {
  pub fn new() -> DraftPost {
    DraftPost {
      content: String::new(),
    }
  }

  pub fn add_text(&mut self, text: &str) {
    self.content.push_str(text);
  }

  pub fn content(&self) -> &str {
    &self.content
  }

  pub fn request_review(&mut self) {
    if let Some(s) = self.state.take() {
      self.state = Some(s.request_review())
    }
  }

  pub fn approve(&mut self) {
    if let Some(s) = self.state.take() {
      self.state = Some(s.approve())
    }
  }
}

impl DraftPost {
  pub fn add_text(&mut self, text: &str) {
    self.content.push_str(text);
  }

  pub fn request_review(self) -> PendingReviewPost {
    PendingReviewPost {
      content: self.content,
    }
  }
}

pub struct PendingReviewPost {
  content: String,
}

impl PendingReviewPost {
  pub fn approve(self) -> Post {
    Post {
      state: None,
      content: self.content
     }
  }
}

trait State {
  fn request_review(self: Box<Self>) -> Box<dyn State>;
  fn approve(self: Box<Self>) -> Box<dyn State>;
  fn content<'a>(&self, post: &'a Post) -> &'a str {
    ""
  }
}

struct Draft {}

impl State for Draft {
  fn request_review(self: Box<Self>) -> Box<dyn State> {
    Box::new(PendingReview {})
  }

  fn approve(self: Box<Self>) -> Box<dyn State> {
    Box::new(Published {})
  }
}

struct PendingReview {}

impl State for PendingReview {
  fn request_review(self: Box<Self>) -> Box<dyn State> {
    self
  }

  fn approve(self: Box<Self>) -> Box<dyn State> {
    Box::new(Published {})
  }
}

struct Published {}

impl State for Published {
  fn request_review(self: Box<Self>) -> Box<dyn State> {
    self
  }

  fn approve(self: Box<Self>) -> Box<dyn State> {
    self
  }

  fn content<'a>(&self, post: &'a Post) -> &'a str {
    &post.content
  }
}
// 블로그 크레이트

pub fn run () {
  let mut post = Post::new();

  post.add_text("I ate a salad for lunch today");

  let post = post.request_review();

  let post = post.approve();

  assert_eq!("I ate a salad for lunch today", post.content());
}