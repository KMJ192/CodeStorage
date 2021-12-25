const prevResultList = [
  {
    deployment_worker_id: 30,
  },
  {
    deployment_worker_id: 20,
  },
  {
    deployment_worker_id: 10,
  },
];

const nextResultList = [
  {
    deployment_worker_id: 40,
  },
  {
    deployment_worker_id: 30,
  },
  {
    deployment_worker_id: 20,
  },
  {
    deployment_worker_id: 10,
  },
];

function test() {
  let updateIdx = [];
  let pointer = {
    next: 0,
    prev: 0,
  };
  while (
    pointer.next <= prevResultList.length ||
    pointer.prev <= nextResultList.length
  ) {
    console.log(prevResultList[pointer.prev].deployment_worker_id);
    console.log(nextResultList[pointer.next]);
    // if (
    //   prevResultList[pointer.prev].deployment_worker_id <
    //   nextResultList[pointer.next].deployment_worker_id
    // ) {
    //   pointer.prev++;
    // } else if (
    //   prevResultList[pointer.prev].deployment_worker_id >
    //   nextResultList[pointer.next].deployment_worker_id
    // ) {
    //   pointer.next++;
    // } else {
    //   pointer.next++;
    //   pointer.prev++;
    // }
    pointer.next++;
    pointer.prev++;
  }
}

test();
