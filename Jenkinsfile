pipeline {
    agent { docker { dockerfile true }}
    stages {
        stage('Run'){
            steps{
                sh 'gcc -o /C_ADTs/Lists/List/Exer/main /C_ADTs/Lists/List/Exer/main.c /C_ADTs/Lists/List/Exer/linked_list.c'
                sh '/C_ADTs/Lists/List/Exer/main'
            }
        }
    }
}