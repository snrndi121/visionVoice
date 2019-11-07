### TO_KOREAN
1. 목적    
- 전체 대화에서 모음들을 숫자 타입의 문자열로 변환된 상태(G0)가 존재하는 상태에서, 카메라가 인식하는 입술의 모양들 또한 모음을 기준으로 숫자 문자열(Gx)로 변환합니다. (x = 1, 2, 3...)    
- 이를 통하여, 전체 숫자 문자열에서 특정 문자열을 찾아내는 문제로 변환하여 화자 분리를 시도할 계획입니다. 이 과정에서, '유전 알고리즘'을 이용하여 기본적인 입술 모양에 대한 오인식에 대비를 할 것 입니다.    
2. 가정 (사전 단계)    
- 현재 전체 대화의 모음들은 숫자 형태로 변환된 상태 : G0
- 상대방의 발화로부터 추출된 모음 또한 하나의 토큰 형태로 존재 : Gx
- G0와 Gx 모두 기본적으로 오인식에 따른 문제는 내재하고 있으나, 주요 쟁점은 영상 인식 당시의 오인식으로 발생한 Gx가 음성 인식으로 변환된 G0보다 더 큰 비중을 다루고 있음. 따라서 본 알고리즘에서는 Gx에 대한 변인 작업을 주 내용으로 다루고자 함.
- 연속적으로 대화를 함. 따라서, 입을 다문 상태는 없다고 가정한다.

3. 유전 알고리즘    
*코멘트 : 유전알고리즘은 특정 코드가 아니라 방법론에 가깝습니다. 특정 염색체 집합으로부터 적합도가 가장
    좋은 염색체를 선택하고 선택된 해의 방향으로 검색을 반복하며 최적해를 찾아가는 구조로 동작합니다.*    
 - 3.1 문자열 의미    
    - 각 입모양에 대하여 특정 숫자 문자로 치환하는 과정이 앞서 사전 과제로 수행되었음을 가정함. 이에 대한 보충 설명을 첨부함.    
    - 이 작업을 이해함에 있어서 중요합니다. 입모양이란 것은 어떻게 보면 매우 불명확한 부분이 있습니다. 따라서, 이런 타입을 정의함에 있어서 아래의 선언 단계에서 '{}'이 의미하는 것은 같은 카테고리에 있는 입모양을 의미합니다. 즉, 발음되는 이미지상 유사한 형태를 지니고 있음을 뜻합니다. 그렇기 때문에, G0에서 가령 'ㅢ', 'ㅙ'를 찾는 것이 아니라, SHAPE_OE('A')를 찾는 작업으로 이해하면 됩니다.    
    - motherword.hpp    
    ```//입술 모양이 한 번인 모음   
      enum Mother_Word {    
         SHAPE_NONE = '0',  //입 다문 상태, , {}    
         SHAPE_A = '1', //'아'발음, , {}    
         SHAPE_EU = '2',//'어'발음, , {}   
         SHAPE_O = '3',//'오'발음, , {}   
         SHAPE_U = '4',//'우'발음, , {'유'}   
         SHAPE_UI = '5',//'으'발음, , {'의'}   
         SHAPE_I = '6',//'이'발음, , {}   
         SHAPE_E = '7'//'에'발음, , {'애'}   
      };
      //입술 모양이 두번 이상 변하는 모음   
      enum StepMother_Word {   
        SHAPE_IA = '8', //'야' 발음, '이' + '아', {}   
        SHAPE_IEU = '9',//'여' 발음, '이' + '어', {}   
        SHAPE_OE = 'A',//'외' 발음, '오' + '에', {'왜', '웨'}   
        SHAPE_UEU = 'B',//'워' 발음, '우' + '어', {}   
        SHAPE_IE = 'C',//'얘' 발음, '이' + '에', {}   
        SHAPE_OA = 'D',//'와' 발음, '오' + '아', {}   
        SHAPE_WE = 'E',//'위' 발음, '우' + '이', {}   
        NOT_FOUND ='F'   
      };```   
 - 3.2 룰렛휠   
  *코멘트 : 자손을 생성할 때 두 개의 부모 염색체를 생성함에 있어서 '적합도'에 의존하면 '염색체의 다양성'   
  을 훼손할 수 있기 때문에 전역 최적해를 찾기에는 부적합함. 따라서, 유전 알고리즘에서는 일반적으로   
  룰렛 휠 선택 방법을 이용함.*    
    - 3.2.1 스코어링    
      *코멘트 : 특정 유전자열에 대한 우위를 매기기 위해서는, 얼마나 연속적 형태가 G0 내에 나타났는지 & 현재 검색 인덱스 기준으로 얼마나 가까이 위치해 있는지에 따라 점수화할 것임.*    
      - 3.2.1.1 연속적 형태    
        - 가장 이상적인 형태는 Gx가 G0 안에서 완벽히 일치된 형태로 존재하는 것임. 다만, 유전자 열의 일부가 일치하지 않을 수 있음. 따라서 이 부분에 대한 가중치를 부여해야함.    
      - 3.2.1.2 어떤 위치    
        - 특정 유전자들(Gx)이 G0 안에서 동어 반복으로 인하여 중복되게 발생할 수 있음. 그럴 경우에는, 현재 검색 인덱스 기점으로 가장 가까운 유전자열을 선택해야함.
      - 3.3.1.3 식    
          ```
            * Score(Gx) = how_sequential(x) * found_location(x),   
            * how_sequential(Gx) = correct_word(a) * 8 - wrong_word(n - a) * 2,   
            * found_location(Gx) = n / (found_index - current_search_index),   
            * n : 염색체 길이, a : GO에서 n 단위 탐색이 Gx와 일치한 문자열 개수   
          ```
          - how_sequential : 전체 문자열을 탐색하면서 일치한 정보와 그렇지 않은 정보간의 가중치 합산    
          - found_location : 현재 탐색 지점으로부터 멀리 떨어질 수록 가중치를 낮추는 작업    
    - 3.2.1 확률 변환(1)    
      - 새로운 자식 Gx를 만들어 내는 과정에서 현재 Gx를 기준으로 단순하게 조합 가능한 형태 부모들을 만들어 낼 것임.(*3.4 돌연변이 참고*) 이후에 각 부모들에 대한 확률 값을 계산을 해야함.    
      - '얼마나 자주 나타났는 지'에 따라서 부모 염색체를 선택하는 과정임.    
      - 최대 반복 횟수 100,    
      ```
        P(chj) = (100 / Score(Gx))^2
      ```
    - 3.2.2 확률 변환(2)    
      - 각 언어마다 가장 많이 쓰이는 모음들이 있다고 가정하고 이를 토대로 각 염색체들에 대한 확률을 계산을 시도해볼 수 있을 것임.    
      - 그러나, 현재는 확률 변환(1) 단계로 수행할 예정.    

  - 3.3 돌연변이    
  *코멘트 : 두 번이상 입모양이 변하는(Enum StepMother_Word type)일 경우, 문자열 상에서 한 모음 타입(Enum Mother_word)의 조합으로 나타날 것임. 따라서, 이 내용에 따라서 변이를 고려해아햠.아울러서, 한 모양 타입(Enum Mother_word)일 경우도 이미지상 유사한 경우도 있으므로 반영해야함.*    
    - 3.3.1 한 모양 타입(Mother_word) -> 두 모양 타입(StepMother_word)    
    ```
      - SHAPE_IA <= SHAPE_I + SHAPE_A,   //'야' 발음, '이' + '아'   
      - SHAPE_IEU <= SHAPE_I + SHAPE_EU,//'여' 발음, '이' + '어', {}   
      - SHAPE_OE <= SHAPE_O + SHAPE_E, //'외' 발음, '오' + '에', {'왜', '웨'}   
      - SHAPE_UEU <= SHAPE_U + SHAPE_EU,//'워' 발음, '우' + '어', {}   
      - SHAPE_IE <= SHAPE_I + SHAPE_E,//'얘' 발음, '이' + '에', {}   
      - SHAPE_OA <= SHAPE_O + SHAPE_A,//'와' 발음, '오' + '아', {}   
      - SHAPE_WE <= SHAPE_U + SHAPE_I,//'위' 발음, '우' + '이', {}   
    ```
    - 3.3.2 한 모양 타입 간 변이    
    ```
      - SHAPE_A <=> SHAPE_EU,   
      - SHAPE_EU <=> SHAPE_A,   
      - SHAPE_O <=> SHAPE_U,   
      - SHAPE_U <=> SHAPE_O,   
      - SHAPE_UI <=> SHAPE_I,   
      - SHAPE_I <=> SHAPE_UI, SHAPE_E,   
      - SHAPE_E <=> SHAPE_I,   
    ```
    - 3.3.3 세대 수와 돌연 변인 확률    
      - 세대 수 : 4,
      - 돌연변이 확률 : 0.1

4. 입력 형태    
  - 설명    
    - line 1, 전체 테스트 세트 개수,
    - line 2, 찾을 발화 문자열의 개수,
    - line 3, 전체 발화 문자열 G0,
    - line 4 ~ n + 2, 찾을 발화 문자열 Gx
  - 예시    
  ```
    line 1 : 2 //테스트 세트 개수   
    line 2 : 5  //Gx 개수   
    line 3 : 12356162735715263616236126351263635126316236162351623612636162636162   
    line 4 : 35126   
    line 5 : 516236   
    line 6 : 526361623612   
    line 7 : 1623613   
    line 8 : 133571526   
    line 9 : 2  //Gx 개수   
    line 10 : 1235616273571526361B23612635C263635126316236162351623612636162636162   
    line 11 : 3614223   
    line 12 : 6726   
  ```
5. 출력 형태    
  - 설명    
    - line 1 ~ n - 1 : 찾을 문자열(Gx)을 탐색한 해에 대한 정보를 나타냅니다. 첫 열 정보는 변이 과정이 거쳐서 도출한 해인지 알려주고, 0일 경우 변이는 없었음을 뜻합니다. 두 번째는, 원래 찾고자 한 문자열에 대한 정보를 알려주고, 세 번째 열의 경우는 실제로 G0로부터 찾은 문자열에 대한 정보를 알려줍니다.    
      ex) line 1, 변이 과정없이 타겟 G1을 찾았음을 의미합니다.    
      ex) line 4, 변이 과정이 존재하였고 타겟 G4에서 마지막 문자(3)이 탈락하고 2가 변이가 나타났습니다.    
  - 예시    
  ```
    line 1 : 0 35126 35126   
    line 2 : 0 516236 516236   
    line 3 : 0 526361623612 526361623612   
    line 4 : 1 1623613 1623612   
    line 5 : 1 133571526 3571526   
    line 6 : 1 3614223 361B23
    line 7 : 1 6726 C26
  ```
6. 마무리    
  - 영상으로 화자 분리를 하기 위하여 문제를 전환해봤습니다. 너무나 많은 변이와 치환 작업이 소요되겠지만 추후에 좀 더 정확한 방법 또한 생각을 해보겠습니다.    
  - 음성 파형을 통하여 화자 분리를 하는 아마존의 Transcribe 나 Github 내에 여러 작업물을 참고하여 성공해보겠습니다.    
    
### TO_ENGLISH (translated above)
1. Purpose
- In the whole dialogue, the vowels are converted to strings of numeric type (G0), and the shape of the lips recognized by the camera   is also converted to the numeric string (Gx) based on the vowels. (x = 1, 2, 3 ...)    
- Through this, we plan to try to split the speaker by converting it to the problem of finding a specific string in the whole number string. In this process, we will use 'genetic algorithms' to prepare for misunderstanding of basic lip shape.    

2. Pre-condition   
  - The entire collection of conversations is now converted to numbers: G0
  - A vowel extracted from the opponent's speech also exists in the form of a token: Gx
  - Both G0 and Gx basically have a problem due to misrecognition, but the main issue is misrecognition at the time of image recognition. The Gx generated by G2 is larger than the G0 converted to speech recognition. Therefore, in this algorithm will mainly focus on the variable work on Gx.
  - This problem considers consecutive conversations. Therefore, it is assumed that there is no shut state.

3. Genetic algorithm  
  *comment : Genetic algorithms are more a methodology than a specific code. It works by selecting a chromosome with the best fit from a specific set of chromosomes, repeating the search in the direction of the selected solution, and finding the optimal solution.*    
  - 3.1 Digit String meaning   
  - It is assumed that the process of substituting a specific numeric character for each mouth shape was performed as a prior task. A supplementary explanation is attached.
  - It is important to understand this task. The shape of the mouth is very unclear in some ways. Thus, in defining these types, the meaning of '{}' in the declaration phase below means mouths in the same category. That is, it has a similar shape in the image that is pronounced. That's why G0 doesn't look like 'ㅢ', 'ㅙ', but rather the task of finding SHAPE_OE ('A').
    - motherword.hpp   
    ```  
      enum Mother_Word {   
         SHAPE_NONE = '0',  //shut state, , {}   
         SHAPE_A = '1', //sound 'A', , {}   
         SHAPE_EU = '2',//sound 'ə', , {}   
         SHAPE_O = '3',//sound 'O', , {}   
         SHAPE_U = '4',//sound 'U', , {'ju'}   
         SHAPE_UI = '5',//sound 'UI', , {}   
         SHAPE_I = '6',//sound 'I', , {}   
         SHAPE_E = '7'//sound 'E', , {'ae'}   
      };
      //Collection of lips changing more than once
      //I'm a korean, so it can't be cover english. But I tried you to understand this.
      //thanks.
      enum StepMother_Word {   
        SHAPE_IA = '8', //sound 'ia', 'i' + 'a', (ex)'yamy'   
        SHAPE_IEU = '9',//sound 'ier', 'i' + 'ə', (ex)'year'   
        SHAPE_OE = 'A',//sound 'wuɛər', 'u' + 'ɛər', (ex)'when', 'where'   
        SHAPE_UEU = 'B',//sound 'uər', 'u' + 'ə', (ex)'war','word'   
        SHAPE_IE = 'C',//sound 'iae', 'i' + 'ae', {}   
        SHAPE_OA = 'D',//sound 'oa', 'o' + 'a', (ex)'or'   
        SHAPE_WE = 'E',//sound 'ui', 'wu' + 'i', (ex)'we'   
        NOT_FOUND ='F'   
      };   
    ```   
  - 3.2 Roulette wheel   
  *comment : When producing offspring, depending on the 'fit' in generating two parental chromosomes, it is not suitable to find the global optimal solution because it can undermine 'chromosome diversity'. Therefore, genetic algorithms generally use the roulette wheel selection method..*    
    - 3.2.1 Scoring   
      *comment : To give an advantage over a particular gene sequence, we will score based on how consecutive the shape appears within G0 and how close it is to the current search index.*    
      - 3.2.1.1 Continuous form   
        - The most ideal form is that Gx exists in perfect match within G0. However, some of the gene strings may not match. Therefore, this part should be weighted.   
      - 3.2.1.2 Any location   
        - Certain genes (Gx) may overlap due to synonym repetition in G0. In that case, you should select the nearest gene sequence as the starting point of the current search index.
      - 3.3.1.3 Expression
          ```
            * Score(Gx) = how_sequential(x) * found_location(x),   
            * how_sequential(Gx) = correct_word(a) * 8 - wrong_word(n - a) * 2,   
            * found_location(Gx) = n / (found_index - current_search_index),   
            * n : Chromosome length, a : The number of strings whose n search in GO matches Gx   
          ```
          - how_sequential : Sum the weights between matched and unmatched information as you search the entire string.   
          - found_location : Lower weight as you move away from the current navigation point.   
    - 3.2.1 Probability transformation(1)   
      - In the process of creating a new child Gx, we will create a simple combinable form of parents based on the current Gx (see 3.4  Mutation).
      -The process of selecting the parent chromosome according to 'how often'.
      - Maximum number of iterations : 100,
      ```
        P(chj) = (100 / Score(Gx))^2
      ```
    - 3.2.2 Probability transformation(2)
      - Assuming that each language has the most common vowels, we can try to calculate the probabilities for each chromosome. However, it is currently going to be performed as a probability transformation (1) step.  

  - 3.3 Mutation   
  *comment : If the mouth changes more than once (Enum StepMother_Word type), it will appear as a combination of one vowel type (Enum Mother_word) on the string. Thus, variations should be considered in accordance with this content. In addition, one shape type (Enum Mother_word) may be similar in the image and should be reflected.*    
    - 3.3.1 One shape type(Mother_word) -> Two shape type(StepMother_word)   
    ```
      - SHAPE_IA <= SHAPE_I + SHAPE_A,   
      - SHAPE_IEU <= SHAPE_I + SHAPE_EU,   
      - SHAPE_OE <= SHAPE_O + SHAPE_E,   
      - SHAPE_UEU <= SHAPE_U + SHAPE_EU,   
      - SHAPE_IE <= SHAPE_I + SHAPE_E,   
      - SHAPE_OA <= SHAPE_O + SHAPE_A,    
      - SHAPE_WE <= SHAPE_U + SHAPE_I,    
    ```
    - 3.3.2 Transition Between One Shape Type   
    ```
      - SHAPE_A <=> SHAPE_EU,   
      - SHAPE_EU <=> SHAPE_A,   
      - SHAPE_O <=> SHAPE_U,   
      - SHAPE_U <=> SHAPE_O,   
      - SHAPE_UI <=> SHAPE_I,   
      - SHAPE_I <=> SHAPE_UI, SHAPE_E,   
      - SHAPE_E <=> SHAPE_I,   
    ```
    - 3.3.3 Generation number and probability of mutation  
      - Generation number : 4   
      - probability of mutation : 0.1   

4. Input mode    
- comment    
    - line 1, Total test set count
    - line 2, The number of speech strings to find   
    - line 3, Full digits string G0  
    - line 4 ~ n + 2, target digits string Gx   
- example    
  ```
    line 1 : 2 //Total test set count  
    line 2 : 5  //The number of speech strings to find   
    line 3 : 12356162735715263616236126351263635126316236162351623612636162636162   
    line 4 : 35126   
    line 5 : 516236   
    line 6 : 526361623612   
    line 7 : 1623613   
    line 8 : 133571526   
    line 9 : 2  //The number of speech strings to find   
    line 10 : 1235616273571526361B23612635C263635126316236162351623612636162636162   
    line 11 : 3614223   
    line 12 : 6726   
  ```
5. output mode   
- comment   
    - line 1 ~ n - 1 : Indicates information about the year in which to search for the string to find (Gx). The first column of information tells you whether the year was derived through the transition process, and 0 means no mutation. The second gives you information about the string you were originally looking for, and the third column tells you about the string you actually found from G0.   
      ex) line 1, This means that we found the target G1 without any mutation.   
      ex) line 4, There was a mutation process and the last letter (3) was dropped from target G4 and a bivalent mutation appeared.   
- example   
  ```
    line 1 : 0 35126 35126   
    line 2 : 0 516236 516236   
    line 3 : 0 526361623612 526361623612   
    line 4 : 1 1623613 1623612   
    line 5 : 1 133571526 3571526   
    line 6 : 1 3614223 361B23
    line 7 : 1 6726 C26
  ```   
6. Wrap-up   
- I switched the problem to separate the speaker into the video. It will take too many variations and substitutions, but I will think about more accurate methods later.   
- I'll succeed by referring to the various pieces of work within Transcribe or Github on Amazon that use speaker separation through speech waveforms.   
