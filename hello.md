graph TD
    %% --- STYLE DEFINITION ---
    classDef terminal fill:#2d3436,stroke:#000,color:#fff
    classDef process fill:#f1f2f6,stroke:#2f3542,stroke-width:1px
    classDef decision fill:#dfe4ea,stroke:#2f3542,stroke-width:2px
    classDef io fill:#e8f4fd,stroke:#3498db,stroke-width:1px
    classDef subproc fill:#ffffff,stroke:#2f3542,stroke-width:2px

    %% --- FLOW START ---
    Start([START]) --> Init[Inisialisasi Matriks A, B, C, D, E <br/>isCreated = false]
    
    Init --> Menu[/Tampilkan Menu & Input pilihan/]

    %% --- VALIDATION LAYER ---
    Menu --> IsNumber{Apakah <br/>Angka?}
    
    IsNumber -- Tidak --> WarnInput[/Print: Input harus angka/] --> Menu
    
    IsNumber -- Ya --> CheckCreated{pilihan 2-7 <br/>& !isCreated?}
    
    CheckCreated -- Ya --> WarnData[/Print: Matriks belum dibuat/] --> Menu

    %% --- DECISION CENTER (ROUTING) ---
    CheckCreated -- Tidak --> Router{Pilihan <br/>Menu?}

    %% --- PROCESS LAYER (FUNCTIONS) ---
    Router -- 1 --> Op1[[buatSemuaMatriks]]
    Router -- 2 --> Op2[[cetakMatriks A, B, D]]
    Router -- 3 --> Op3[[tambahMatriks A+B]]
    Router -- 4 --> Op4[[kaliMatriks D*A]]
    Router -- 5 --> Op5[[cetakDiagonal A]]
    Router -- 6 --> Op6[[cetakSegitigaBawah A]]
    Router -- 7 --> Op7[[cetakSegitigaAtas A]]

    %% --- RETURN PATHS ---
    Op1 --> SetFlag[isCreated = true] --> Menu
    Op2 & Op3 & Op4 & Op5 & Op6 & Op7 --> Menu

    %% --- EXIT LAYER ---
    Router -- 8 --> ExitMsg[/Print: Program Selesai/]
    ExitMsg --> End([END])

    Router -- Lainnya --> Default[/Print: Pilihan tidak valid/] --> Menu

    %% --- APPLYING SHAPES/CLASSES ---
    class Start,End terminal
    class Init,SetFlag process
    class IsNumber,CheckCreated,Router decision
    class Menu,WarnInput,WarnData,ExitMsg,Default io
    class Op1,Op2,Op3,Op4,Op5,Op6,Op7 subproc