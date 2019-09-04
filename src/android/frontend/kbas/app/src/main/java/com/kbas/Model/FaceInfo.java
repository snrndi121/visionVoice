package com.kbas.Model;
/*
   * 비언어적 요소
   * 감정적 측면 + 태도적 측면
   * 감정적 측면 -> OK
   * 태도적 측면 = {
   *                1) 시선의 방향 상태 {은행원으로 || 그 외}
*                +  2) 청취 자세 상태 {앞으로 기울어짐 || 뒤로 기울어짐 || 옆으로 기울어짐 || 정상}
*                +  3) 눈 깜빡임 횟수
*                +  4) 질문 횟수
*
*/
class FaceInfo extends BaseModel {
    private final int EMO_NUM = 8;
    //todo : 순서 있을듯
    private float[] emotionsChange = new float[EMO_NUM];//emotions
    private int mouthOpenCount;//how many tallk
    private int eyeBlicnkCount;//how many eyes will blink
    private int HeadLocCount;//a change of a location of head
    private float sizeOfHeadRect;

    public FaceInfo(){};
    public void setEmotionsChange(float[] emotionsChange) {
        this.emotionsChange = emotionsChange;
    }

    public void setHeadLocChange(int headLocChange) {
        HeadLocCount = headLocChange;
    }

    public void setEyeBlicnkCount(int eyeBlicnkCount) {
        this.eyeBlicnkCount = eyeBlicnkCount;
    }

    public void setMouthChange(int mouthOpenCount) {
        this.mouthOpenCount = mouthOpenCount;
    }
    public void setSizeOfHeadRect(float sizeOfHeadRect) {
        this.sizeOfHeadRect = sizeOfHeadRect;
    }
    public float getEyeBlicnkChange() {
        return eyeBlicnkCount;
    }

    public float getHeadLocChange() {
        return HeadLocCount;
    }

    public float getMouthChange() {
        return mouthOpenCount;
    }

    public float[] getEmotionsChange() {
        return emotionsChange;
    }
    public float getSizeOfHeadRect() {
      return sizeOfHeadRect;
    }
    public void updateEmotions(float[] newEmotions) {
        for (int i = 0; i < EMO_NUM; ++i)
            emotionsChange[i] = (emotionsChange[i] + newEmotions[i])/2;
    }
    public void updateHeadChange(float width, float height) {
        float temp = this.sizeOfHeadRect;
        //algo
        //실제로 변화했는 지 확인
        //this.sizeOfHeadRect = ?
    }
    public void describes() {
        System.out.println("mouthOpenCount" + mouthOpenCount);
        System.out.println("eyeBlicnkCount" + eyeBlicnkCount);
        System.out.println("HeadLocCount" + HeadLocCount);
        for (int i = 0; i < EMO_NUM; ++i) {
            System.out.println("emotionsChange" + emotionsChange[i]);
        }
    }
}
