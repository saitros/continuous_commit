## Decomposing Word Embedding with the Capsule Network

https://arxiv.org/pdf/2004.13844.pdf

  - 방법 :

  sentence embedding (len, embedding_dim)에 대해서 각각의 target word embedding(1, embedding)

  을 기반으로 decompose 하고싶은 dim(p) 만큼 linear expand (1, p) 시키는 Embedding Decompose Module 이 일반적인 context leaning module 과 병렬적으로 계산.

  일반적인 one sentence 의 representation learning 이 아닌 Two sentence 에서 하나의 target word 에 대해 학습하는 방법을 제안 (Word Sense Matching Trainging)

  - 장점 : local context representation과 global context 를 동시에 학습하며, ambiguous word 에 대해 잘 한다더라. 기존의 one sentence 방식보다 수월하게 ambiguous word sense 학습에 용이하다

  - 단점 : decompose dim (p)에 대한 적절한 범위 설정이 중요한것 같아보이는데, 해당 내용에 대한 서술은 없음.


## Supermasks in Superposition

https://arxiv.org/abs/2006.14769

- 방법 :

Random wiring 방법은 아니고 subnetwork 를 탐색하는 방법(?)으로 Traditionally 방식이 f(x, W)라고 했을때, supermask 를 적용해서 f(x, Mask @ W)의 연산을 수행
Mask 가 일정 threshold 를 넘지 못하면 0, 넘으면 1 로 step function 처럼 작용함
random initialize를 반복하며, mask와 동시에 W를 학습.

- 장점 :

결과적으로 puring 된 subnetwork 를 구성할 수 있음

- 단점 :

train 단계에서 W가 걸린 수 만큼 Mask 가 같이 걸려야함. memory 효율성

## MultiLingual Embedding

2차원 공간을 정의하려면 2개의 점이 있어야하고
3차원 공간을 정의하려면 3개의 점이 필요

같은 원리로 n_dim 의 임베딩 공간을 구축할 때 의미가 똑같은 고유명사를 anchor point 로 삼아 trans
(http://www.cs.umd.edu/~myuan/docs/2018_nips_mtanchor.pdf)

## Korean character Embedding

style transfer 를 처음에 생각했으나, eval metric이 모호하다고 판단.
spatial embedding으로 내용을 바꿔보는 아이디어.
기존의 embedding 방식은 token 처리 방식에 의존적이며, token 처리시 해결하지 못하는 oom issue, token stemming 등
다양한 데이터가 존재하게되며, 이에 따라 학습이 힘들어짐. --> spatial 한 embedding 방법으로 연구하면
low resource 측면으로 접근할 수 있지 않을까...요...??

## Pyramid language Transformer

Pyramid vision transformer 의 구조와 비슷하게 지금의 transformer 는 512 token 이 계속 유지되고 있음.

attention scale 하는 과정에서 most 1 과 병합을 하거나 일정 threshold 이상의 token 과 결합되는 방식으로 pyramid 구조의 Language transformer 를 시도해보자는 아이디어

아니면 attention table 을 봤을때(대각 행렬이 자기 자신을 가르키는) 현재는 좌우 양방향에 대한 정보를 동시에 수집. mask 처리된것처럼 각각 attention 을 계산. 이걸 super mask 처럼 ..? 

성능은 비슷하거나 약간의 소실이 있더라도 메모리 및 속도에 성능 향상이 있으면...
