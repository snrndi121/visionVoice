package com.kbas;

import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import com.jjoe64.graphview.GraphView;
import com.jjoe64.graphview.series.DataPoint;
import com.jjoe64.graphview.series.LineGraphSeries;


import androidx.appcompat.app.AppCompatActivity;

public class VisionResActivity extends AppCompatActivity {
    //view
    GraphView mVisionGraph;
    Button mButtonPass;
    boolean isSaved = false;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_vision_res);
        setConfig();
    }
    private void setConfig() {
        //1. graph
        mVisionGraph = (GraphView) findViewById(R.id.graph);
        LineGraphSeries <DataPoint> series = new LineGraphSeries<DataPoint>(readVisionRes());
        //activate Horizontal zooming and scrolling
        mVisionGraph.getViewport().setScalable(true);
        //graph-property
        series.setColor(Color.GREEN);
        series.setThickness(8);
        mVisionGraph.setTitle("고객 음성 모니터");
        mVisionGraph.getViewport().setMinY(-1);
        mVisionGraph.getViewport().setMaxY(1);
        //show
        mVisionGraph.addSeries(series);
        //
        //2. button
        mButtonPass = (Button) findViewById(R.id.button_pass);
        mButtonPass.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (!isSaved) { //아직 저장이 된 상태가 아니라면
                    Toast.makeText(getApplicationContext(), "저장되었습니다.", Toast.LENGTH_SHORT).show();
                    isSaved = true;
                }
                else {
                    Toast.makeText(getApplicationContext(), "이미 저장되어있습니다.", Toast.LENGTH_LONG).show();
                }
            }
        });
    }
    private DataPoint[] readVisionRes() {
        int res_index = 0 ;
        final float time_unit = 10000;
        //원래는 여기에서 생성된 결과 파일을 읽어들여야함.
        //현재는, 최종 샘플에서 도출된 결과를 넣는 작업을 함.
        float vres_start [] = new float[]{31055,36754,40030,48741,53508,59746,66519,70231,76791,79816,96173,104956,111587,114593,121421,126304,130670,142630,147360,168427,186421,198109,200401,207323,217095,228375,231350,236348,247030,269856,278891,283927,293544,299318,315525,321675,325234,328215,335932,346772,350338,360282,364347,367199,371064,375755,388939,391802,396957,407667,411616,420138,426096,431233,443283,458920,467191,471266,480002,484986,508170,514491,522631,527917,548995};
        float vres_end [] = new float[]{33430,39053,42284,52903,57261,65691,69659,74436,79217,82831,101351,107916,113978,117180,124447,128831,135517,145589,149779,172526,196375,200401,205034,214768,225427,231350,234352,240485,249416,272860,282138,286935,295953,302606,319297,324653,327609,331174,338299,349757,359126,362619,367199,369944,373263,377988,391801,395283,399221,410482,415619,423027,430076,436421,449807,463635,469499,478858,483249,489226,510658,516806,525253,530369,553870};
        DataPoint vres [] = new DataPoint[4 * vres_start.length];
        //set Data
        for (int i = 0; i < vres_start.length; ++i) {
            vres [res_index++] = new DataPoint(vres_start[i]/time_unit, 0);
            vres [res_index++] = new DataPoint(vres_start[i]/time_unit, 1);
            vres [res_index++] = new DataPoint(vres_end[i]/time_unit, 1);
            vres [res_index++] = new DataPoint(vres_end[i]/time_unit, 0);
        }
        return vres;
    }
}
