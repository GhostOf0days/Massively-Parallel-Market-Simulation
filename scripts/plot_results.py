import matplotlib.pyplot as plt
import csv

def plot_asset_prices():
    prices = []
    with open('results/market_snapshots/snapshot_99.csv', 'r') as file:
        csv_reader = csv.reader(file)
        next(csv_reader)  # Skip the header row
        for row in csv_reader:
            prices.append(float(row[1]))
    plt.figure(figsize=(10, 6))
    plt.plot(prices)
    plt.xlabel('Asset')
    plt.ylabel('Price')
    plt.title('Asset Prices at Final Time Step')
    plt.grid(True)
    plt.savefig('results/asset_prices.png')
    plt.close()

def plot_trader_balances():
    balances = []
    with open('results/market_snapshots/snapshot_99.csv', 'r') as file:
        csv_reader = csv.reader(file)
        next(csv_reader)  # Skip the header row
        for row in csv_reader:
            balances.append(float(row[3]))
    plt.figure(figsize=(10, 6))
    plt.bar(range(len(balances)), balances)
    plt.xlabel('Trader')
    plt.ylabel('Balance')
    plt.title('Trader Balances at Final Time Step')
    plt.grid(True)
    plt.savefig('results/trader_balances.png')
    plt.close()

def main():
    plot_asset_prices()
    plot_trader_balances()

if __name__ == '__main__':
    main()