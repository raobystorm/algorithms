import pandas as pd

def solution(files):
    results = []
    for file in files:
        file_res = []
        df = pd.read_csv(file)
        df['year'] = df['date'].astype(str).apply(lambda x: x.split('-')[0])

        vol_max = df.groupby(['year'])['date', 'vol'].max(['vol'])
        vol_res = df.iloc[0:0]

        for row in vol_max.iterrows():
            vol_res = vol_res.append(df.loc[df['year'].eq(row[0]) & df['vol'].eq(row[1]['vol'])])

        vol_res = vol_res.drop(columns=['year', 'close', 'open', 'min', 'max'])
        file_res.append(vol_res)

        close_max = df.groupby(['year'])['date', 'close'].max(['close'])
        close_res = df.iloc[0:0]
        for row in close_max.iterrows():
            close_res = close_res.append(df.loc[df['year'].eq(row[0]) & df['close'].eq(row[1]['close'])])

        close_res = close_res.drop(columns=['year', 'vol', 'open', 'min', 'max'])
        file_res.append(close_res)

        results.append(file_res)

    return results

print(solution(["./phksha/test.csv"]))